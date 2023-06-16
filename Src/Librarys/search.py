import os

def File_CSourceList(dir):
    result = []
    if ( not os.path.exists(dir) ):
        return result
    if ( os.path.isfile(dir) ):
        if ( "c" == dir.split('.')[-1].lower() ):
            result.append(dir)
        return result
    if ( os.path.isdir(dir) ):
        with os.scandir(dir) as dirEntryList:
            for curSubEntry in dirEntryList:
                curSubEntryFullPath = os.path.join(dir,curSubEntry.name)
                if ( curSubEntry.is_dir ):
                    result.extend(File_CSourceList(curSubEntryFullPath))
                elif ( curSubEntry.is_file ):
                    if ( "c" == curSubEntry.name.split('.')[-1].lower() ):
                        result.append(curSubEntryFullPath)
        return result

CFileList = File_CSourceList(".")
with open("csourcelist.txt","w") as f:
    for FileItem in CFileList:
        f.write(FileItem+" \\\n")
