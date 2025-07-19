class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new ArrayList<>();
        String parentFolder = "*";
        for(int i = 0; i < folder.length; i++){
            if(!folder[i].startsWith(parentFolder)){
                res.add(folder[i]);
                parentFolder = folder[i] + "/";
            }
        }
        return res;
    }
}