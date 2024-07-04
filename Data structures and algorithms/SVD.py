import numpy as np

orig_arr = [[1, 2], [3, 4], [5, 6]]
orig_arr_np = np.array(orig_arr)

# Find U
to_extract_u = orig_arr_np @ orig_arr_np.T

eig_val_u, eig_vec_u = np.linalg.eig(to_extract_u)

print(eig_val_u)
print(eig_vec_u)

# Find V^T
to_extract_v = orig_arr_np.T @ orig_arr_np

eig_val_v, eig_vec_v = np.linalg.eig(to_extract_v)

print(eig_val_v)
print(eig_vec_v)

print(eig_val_u[0] - eig_val_v[1])
print(eig_val_u[1] - eig_val_v[0])
