drawoption = input('Please input drawoption\n');
dt = input('Please input dt\n');
starttime = input('Please input start time\n')
endtime = input('Please input end time\n')
for i=starttime:dt:endtime
    switch(drawoption)
        case 0
            %Output Potential Temperature
            subplot(2,2,1);
            plotOutput('th',i);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Potential Temperature,t=%d',i);
            title(titlestring);    


            %Output Nondimensional Pressure
            subplot(2,2,2);
            plotOutput('pi',i);
            caxis([-25 25]);
            colorbar;
			titlestring = sprintf('Nondimensional Pressure,t=%d',i);
            title(titlestring);    			



            %Output Horizontal Wind Speed
            subplot(2,2,3);
            plotOutput('u',i);
            caxis([-5 5]);
            colorbar;
			titlestring = sprintf('Horizontal Wind Speed,t=%d',i);
            title(titlestring);    			           


            %Output Vertical Wind Speed
            subplot(2,2,4);
            plotOutput('w',i);
            caxis([-10 10]);
            colorbar;
			titlestring = sprintf('Vertical Wind Speed,t=%d',i);
            title(titlestring);    						

            
        case 1
            %Output Potential Temperature
            plotOutput('th',i);
            caxis([-20 20]);
            colorbar;
			titlestring = sprintf('Potential Temperature,t=%d',i);
            title(titlestring);     

        case 2
            %Output Nondimensional Pressure
            plotOutput('pi',i);
            caxis([-25 25]);
            colorbar;
			titlestring = sprintf('Nondimensional Pressure,t=%d',i);
            title(titlestring);    			

        case 3
            %Output Horizontal Wind Speed
            plotOutput('u',i);
            caxis([-5 5]);
            colorbar;
			titlestring = sprintf('Horizontal Wind Speed,t=%d',i);
            title(titlestring);    	

        case 4
            %Output Vertical Wind Speed
            plotOutput('w',i);
            caxis([-10 10]);
            colorbar;
			titlestring = sprintf('Vertical Wind Speed,t=%d',i);
            title(titlestring);    						
    end
    
    pause(0.2);  
    clf;
end