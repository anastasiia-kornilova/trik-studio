import subprocess
import sys
import os
from typing import Iterable, List


def get_files(dir: str) -> Iterable[str]:
	return sorted(os.path.join(dir, p) for p in os.listdir(dir))

if __name__=='__main__':
	bin_path = sys.argv[1]

	num_failed_tests = 0
	for f in list(get_files(sys.argv[2])):
#		output = subprocess.run([bin_path, '-b', '-s', '20', f], capture_output=True)
		print(f)
#		print("Return code : %d. " % output.returncode)
#		print("Message: %s" % output.stderr.encode("utf-8"))
#		if (output.returncode != 0):
#			print("Solution failed with return code %d " % output.returncode)
#			num_failed_tests += 1
		
	if num_failed_tests == 0:
		sys.exit(0)
	else:
		sys.exit(1)
