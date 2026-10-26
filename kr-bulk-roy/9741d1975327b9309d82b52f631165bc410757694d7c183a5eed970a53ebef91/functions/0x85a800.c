
void FUN_0085a800(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int *local_2c;
  undefined1 local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((in_ECX != 0) && (*(int *)(in_ECX + 0xec) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0xec) + 4))(*(int **)(in_ECX + 0xec));
    piVar1 = *(int **)(in_ECX + 0xec);
    if (piVar1 != (int *)0x0) {
      if (param_2 == (int *)0x0) {
        if (param_1 != 0) {
          (**(code **)(*piVar1 + 0x94))(piVar1,param_1,0);
          (**(code **)(*piVar1 + 8))(piVar1);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        (**(code **)(**(int **)(in_ECX + 0x42c) + 4))(*(int **)(in_ECX + 0x42c));
        piVar2 = *(int **)(in_ECX + 0x42c);
        (**(code **)(*piVar1 + 0x94))(piVar1,0,piVar2);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
      else {
        (**(code **)(*param_2 + 0x44))(param_2,0,local_28);
        local_2c = (int *)0x0;
        (**(code **)(*param_2 + 0x48))(param_2,0,&local_2c);
        (**(code **)(*piVar1 + 0x94))(piVar1,param_1,local_2c);
        if (local_2c != (int *)0x0) {
          (**(code **)(*local_2c + 8))(local_2c);
          (**(code **)(*piVar1 + 8))(piVar1);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      (**(code **)(*piVar1 + 8))(piVar1);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

