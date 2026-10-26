
void FUN_00441f70(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 local_24;
  undefined2 local_1f;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 900) {
    if ((in_ECX[0x3d] != 0) && ((*(uint *)(in_ECX[0x3d] + 0x28) >> 8 & 1) != 0)) {
      FUN_00443da0();
      FUN_00749970((*(int *)(in_ECX[0x3d] + 0x2c) - *(int *)(in_ECX[0x3d] + 0x34)) + local_18,
                   local_14);
      FUN_004418a0();
    }
    if ((in_ECX[0x3e] != 0) && ((*(uint *)(in_ECX[0x3e] + 0x28) >> 8 & 1) != 0)) {
      FUN_00443da0();
      FUN_00749970(local_10,local_14);
      FUN_00749920(in_ECX[0x3e]);
    }
  }
  else if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(in_ECX[0x5d] + 0x20) == iVar1) {
      FUN_0068a1b0(in_ECX[0x3f],in_ECX[0x53]);
      return;
    }
    if (*(int *)(in_ECX[0x5e] + 0x20) == iVar1) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(in_ECX[0x50] + 0x20) == iVar1) {
      local_24 = 0;
      FUN_00442710(in_ECX,&local_24);
      return;
    }
    if (*(int *)(in_ECX[0x51] + 0x20) == iVar1) {
      local_24 = 1;
      FUN_00442710(in_ECX,&local_24);
      return;
    }
    if (*(int *)(in_ECX[0x5c] + 0x20) == iVar1) {
      FUN_00442430();
      return;
    }
  }
  else if (iVar1 == 0xf43a9) {
    local_1d = FUN_00441c80();
    local_1c = (undefined1)in_ECX[0x40];
    local_19 = (undefined1)in_ECX[0x49];
    local_1f = 0x102;
    local_1a = (undefined1)in_ECX[0x48];
    local_1b = (undefined1)in_ECX[0x41];
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1f,7);
      return;
    }
  }
  return;
}

