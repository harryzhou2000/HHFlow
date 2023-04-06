function lines = getFileLines(file)

lines = {};
f = fopen(file);
while (~ feof(f))
   lines{end+1} = fgets(f);
end
lines = lines';
fclose(f);