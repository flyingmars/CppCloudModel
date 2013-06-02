drawoption = input('Please input drawoption\n');
dt = input('Please input dt\n');
starttime = input('Please input start time\n');
endtime = input('Please input end time\n');
outputperGraph = input('Please output per graph\n');

thfid = fopen('th.txt','r');
wfid = fopen('w.txt','r');
ufid = fopen('u.txt','r');
pifid = fopen('pi.txt','r');

for i=starttime:(outputperGraph*dt):endtime

    switch(drawoption)
        case 0
            %Output Potential Temperature
            subplot(2,2,1);
            plotOutput(thfid);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Potential Temperature,t=%d',i);
            title(titlestring);    


            %Output Nondimensional Pressure
            subplot(2,2,2);
            plotOutput(wfid);
            caxis([-25 25]);
            colorbar;
			titlestring = sprintf('Nondimensional Pressure,t=%d',i);
            title(titlestring);    			



            %Output Horizontal Wind Speed
            subplot(2,2,3);
            plotOutput(ufid);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Horizontal Wind Speed,t=%d',i);
            title(titlestring);    			           


            %Output Vertical Wind Speed
            subplot(2,2,4);
            plotOutput(pifid);
            caxis([-10 10]);
            colorbar;
			titlestring = sprintf('Vertical Wind Speed,t=%d',i);
            title(titlestring);    						

            
        case 1
            %Output Potential Temperature
            plotOutput(thfid);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Potential Temperature,t=%d',i);
            title(titlestring);     

        case 2
            %Output Nondimensional Pressure
            plotOutput(pifid);
            caxis([-25 25]);
            colorbar;
			titlestring = sprintf('Nondimensional Pressure,t=%d',i);
            title(titlestring);    			

        case 3
            %Output Horizontal Wind Speed
            plotOutput(ufid);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Horizontal Wind Speed,t=%d',i);
            title(titlestring);    	

        case 4
            %Output Vertical Wind Speed
            plotOutput(wfid);
            caxis([-10 10]);
            colorbar;
			titlestring = sprintf('Vertical Wind Speed,t=%d',i);
            title(titlestring);    						
    end
    
    pause(0.01);  
    if (starttime + dt <= endtime )
        clf;
    end
end

fclose(thfid) ;
fclose(wfid) ;
fclose(ufid);
fclose(pifid);

