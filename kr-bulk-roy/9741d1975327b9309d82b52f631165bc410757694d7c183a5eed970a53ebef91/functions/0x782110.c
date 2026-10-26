
undefined4 FUN_00782110(int param_1)

{
  int *in_EAX;
  int local_20 [7];
  
  FUN_00725100(0xffffffe0,0xffffffff,2);
  if ((*(byte *)(*(int *)(*in_EAX + 4) + 0xc + (int)in_EAX) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*in_EAX + 4) + 0x38 + (int)in_EAX) + 0x28))(local_20,0,0,1,1);
  }
  else {
    local_20[0] = -1;
    local_20[1] = 0xffffffff;
    local_20[2] = 0;
    local_20[3] = 0;
  }
  FUN_00781820();
  if (*(int *)(param_1 + 0x68) == local_20[0] + 0x20 + local_20[2]) {
    if (*(int *)(param_1 + 0x5c) == 0x641) {
      return 1;
    }
    OutputDebugStringA("ERROR FILE LOAD : Mismatch File Version \n ");
  }
  return 0;
}

