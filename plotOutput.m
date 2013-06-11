function outputState = plotOutput(fid)
	i = 1 ;
	j = 1 ;
	
	getnum = fscanf(fid,'%f',1) ;
	while( abs(getnum - 192168.0) >= 1E-10)
		if( abs(getnum - 245145.0) >= 1E-10 )
			graphFile(i,j) = getnum ;
			j = j + 1;
		else
			rownum = j ;
			j = 1 ;
			i = i + 1 ;
		end
		
		getnum = fscanf(fid,'%f',1);
    end
    
    graphFiletemp = graphFile(1:760,1:192);
    
    contourf(graphFiletemp');

    
    
	clear graphFile ;
end