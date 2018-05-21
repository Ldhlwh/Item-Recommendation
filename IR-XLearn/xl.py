import xlearn as xl

model = xl.create_ffm()

model.setTrain("tj.ffm")

model.setValidate("vj.ffm")

model.setTest("testj.ffm")


# Some settings about model
model.disableNorm() 
#model.setOnDisk()
#model.disableEarlyStop()

# Setting hyperparameters
param = {
	'task' : 'reg',
	'epoch' : 100,
	'lr' : 0.03,
	'lambda' : 0.006,
	'k' : 80,
	
	#'fold' : 5,
	'stop_window' : 1,
	
	'metric' : 'rmse',
	'opt' : 'adagrad',
	'init' : 0.5,
}


print("++++++Start to fit++++++")
model.fit(param, "1.model")

print("\a")

print("++++++Start to predict++++++")
model.predict("1.model", "pred.txt")
'''

print("++++++Start to CV++++++")
model.cv(param)
'''