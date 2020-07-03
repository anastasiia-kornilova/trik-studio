import subprocess
import sys
import os
from typing import Iterable, List


def get_files(dir: str) -> Iterable[str]:
    return sorted(os.path.join(dir, p) for p in os.listdir(dir))
	
	
def run_2d():
	return_code = []
	binFolder = sys.argv[1]
	num_failed_tests = 0
	for f in list(get_files(sys.argv[2])):
		#print("Running 2D-model on %s" %f)
		print(f)
		output = subprocess.run([binFolder, '-b', '-s', '20', '--report', 'output_report.txt', f], capture_output=True)
		return_code.append("Test %s. " % f + "Return code : %d. " % output.returncode + "Message: %s" % output.stderr.decode("cp1251"))
		if (output.returncode != 0):
			print("Solution failed with return code %d " % output.returncode)
			num_failed_tests += 1
		
	return return_code, num_failed_tests

if __name__=='__main__':
	with open('output.txt', 'w') as file:
		print("Check started ==============================================================================")
		return_code, num_failed_tests = run_2d()
		file.writelines(return_code)
		print("Check ended ================================================================================")
		print("Number of all tests: %d" % len(return_code))
		print("Number of failed tests: %d" % num_failed_tests)
		
		if num_failed_tests == 0:
			sys.exit(0)
		else:
			sys.exit(1)
