function outputState = plotOutput(dataType,outputTime)
    filename = sprintf('Output_%s_%d.txt',dataType,outputTime);
    graphFile = textread(filename); 
    contourf(graphFile');
end