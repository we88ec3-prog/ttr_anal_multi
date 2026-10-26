
void FUN_007347f0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *piStack_5c;
  undefined1 auStack_4c [4];
  undefined1 local_48 [8];
  int local_40;
  tagRECT local_3c;
  tagRECT local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091ccf9;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  piStack_5c = (int *)(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
  ExceptionList = &local_14;
  local_40 = FUN_00891268(0x48);
  puVar2 = (undefined4 *)0x0;
  local_c = 0;
  if (local_40 != 0) {
    puVar2 = (undefined4 *)FUN_00734010();
  }
  local_c = 0xffffffff;
  SetRect(&local_3c,0,0,param_1,in_ECX);
  SetRect(&local_2c,0,0,param_1,in_ECX);
  iVar1 = FUN_007343d0(param_1);
  if (iVar1 < 0) {
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  else {
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_c = 1;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_c = 0xffffffff;
    }
    uVar4 = 0;
    piVar3 = (int *)0x1;
    iVar1 = (**(code **)(*DAT_00fcde2c + 0x48))(DAT_00fcde2c,0,1,0,local_48);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)puVar2[0x11] + 0x48))((int *)puVar2[0x11],0,&stack0xffffffa8);
      if (iVar1 == 0) {
        iVar1 = D3DXLoadSurfaceFromSurface(uVar4,0,auStack_4c,piVar3,0,&piStack_5c,0xffffffff,0);
        if (iVar1 == 0) {
          (**(code **)(*piVar3 + 8))(piVar3);
          (**(code **)(*piVar3 + 8))(piVar3);
          pcVar5 = "Took screenshot";
        }
        else {
          (**(code **)(*piVar3 + 8))(piVar3);
          (**(code **)(*piVar3 + 8))(piVar3);
          pcVar5 = "failed to copy surface!";
        }
      }
      else {
        (**(code **)(*piVar3 + 8))(piVar3);
        pcVar5 = "Failed to GetSurfaceLevel!";
      }
      FUN_006edb10(pcVar5);
    }
    else {
      (**(code **)(*piStack_5c + 8))(piStack_5c);
      FUN_006edb10("Failed to take screen shot (%d)!",1);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}

