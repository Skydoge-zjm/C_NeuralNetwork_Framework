
Here is a  [PyTorch](https://pytorch.org/) implementation of our model.
### Contents
- [Environment](#Environment)
- [Training](#training)
- [Prediction](#Prediction)


## Environment
First, you need to create an environment with python>=3.6:
`conda create -n pytorch python=3.10.9`
`activate pytorch`
Then, you can choose your pytorch version (cpu/gpu).
Our recommended version is :
	`pytorch 2.1.2`
Some other libs you need to install :
	`pip install numpy, scikit-learn, pandas, matplotlib`
##### Data
We provide the data for training and prediction in `./data/q1`

## Training
You can train the model on our time-encoded dataset.
`python train.py`
We provide the trained model `model_state_dict_2.pth`, and you can also train it yourself.
Your trained model will replace our trained model `model_state_dict_2.pth` in `./model`.
Because the random in choosing the data, the outcome of your trained model will not be the same of ours.
If you do not want to replace it, you can open `train.py` and find `line 97` , then replace it with:
`torch.save(model.state_dict(), './model/your_model_name.pth')`

## Prediction
You can use the trained model to predict the line current in 2020-8.
`python predict.py`
If you want to use your trained model instead of ours, open `predict.py`, find `line 12`.
Replace it with : 
`state_dict = torch.load('./model/your_model_name.pth',map_location=device)`
