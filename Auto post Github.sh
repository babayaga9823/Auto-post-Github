echo "Start "
echo "Enter the Directory Path of File to be compiled"
read compliepath
g++ $compliepath
./a.out
echo "Enter the Directory Path to be Git update and pushed"
read dirpath
cd $dirpath
open -a TextEdit $dirpath/README.md
git add *
git commit -m "automatic post"
git push
echo "End "