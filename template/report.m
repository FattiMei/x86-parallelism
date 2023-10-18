function report(filename)
	X = csvread(filename);
	plot(X(:,1), X(:,2));
	xlabel("trial");
	ylabel("cycles");

	%{ 
		faccio una trasformazione del nome del file per questioni estetiche
			[~, name, ~] = fileparts(filename);
			parts = strsplit(name,  '_');
			title(sprintf("%s(%s)", parts{1}, parts{2}));
	%}

end
