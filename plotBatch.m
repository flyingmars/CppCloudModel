drawoption = input('Please input drawoption\n');
dt = input('Please input dt\n');
for i=0:149
    switch(drawoption)
        case 0
            %Output Potential Temperature
            subplot(2,2,1);
            plotOutput('th',i);
            caxis([-20 20]);
            colorbar;
            title('Potential Temperature');    


            %Output Nondimensional Pressure
            subplot(2,2,2);
            plotOutput('pi',i);
            caxis([-25 25]);
            colorbar;
            title('Nondimensional Pressure');


            %Output Horizontal Wind Speed
            subplot(2,2,3);
            plotOutput('u',i);
            caxis([-5 5]);
            colorbar;
            title('Horizontal Wind Speed');	


            %Output Vertical Wind Speed
            subplot(2,2,4);
            plotOutput('w',i);
            caxis([-10 10]);
            colorbar;
            title('Vertical Wind Speed');
            
        case 1
            %Output Potential Temperature
            plotOutput('th',i);
            caxis([-20 20]);
            colorbar;
            title(sprintf('Potential Temperature, time = %d',i*dt));    

        case 2
            %Output Nondimensional Pressure
            plotOutput('pi',i);
            caxis([-25 25]);
            colorbar;
            title(sprintf('Nondimensional Pressure, time = %d',i*dt));

        case 3
            %Output Horizontal Wind Speed
            plotOutput('u',i);
            caxis([-5 5]);
            colorbar;
            title(sprintf('Horizontal Wind Speed, time = %d',i*dt));	

        case 4
            %Output Vertical Wind Speed
            plotOutput('w',i);
            caxis([-10 10]);
            colorbar;
            title(sprintf('Vertical Wind Speed, time = %d',i*dt));
    end
    
    pause(0.2);  
    clf;
end