function outputState = plotOutput(dataType,outputTime)
    filename = sprintf('%d_%s.txt',outputTime,dataType);
    graphFile = textread(filename); 
    contourf(graphFile');
end