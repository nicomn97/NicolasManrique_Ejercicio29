#PBS -l nodes=1:ppn=1,mem=16gb,walltime=00:00:30
#PBS -M n.manrique10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio26


module load anaconda/python3
module load gcc/4.9.4

cd /hpcfs/home/fisi4028/n.manrique10/NicolasManrique_Ejercicio29

gcc -fopenmp holaMundo.c -o holaMundo.x

./holaMundo.x

gcc -fopenmp burgers.c -o burgers.x

./burgers.x > burgers.dat


python3 burgers.py
