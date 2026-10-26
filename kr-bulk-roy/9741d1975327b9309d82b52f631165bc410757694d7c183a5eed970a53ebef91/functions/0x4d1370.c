
void FUN_004d1370(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *in_ECX;
  uint local_38;
  undefined4 local_34;
  int local_30;
  undefined1 local_2c [12];
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a348;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  local_34 = FUN_004c7df0(in_ECX,1);
  if (in_ECX[0xda] != 0) {
    *(undefined4 *)(in_ECX[0xda] + 0x24) = 0;
  }
  (**(code **)(in_ECX[0x3c] + 8))(0x14,uVar2);
  local_38 = (uint)*(ushort *)(in_ECX + 0x22);
  if ((DAT_00fd9260 & 1) == 0) {
    DAT_00fd9260 = DAT_00fd9260 | 1;
    local_8 = 0;
    FUN_004c6790();
    _atexit(FUN_00bcdd60);
    local_8 = 0xffffffff;
  }
  FUN_004c6720(&local_38);
  if ((local_30 != DAT_00fd9268) && ((undefined2 *)(local_30 + 0x10) != (undefined2 *)0x0)) {
    (**(code **)(*in_ECX + 0x68))(*(undefined4 *)(local_30 + 0x14),0x3f800000);
    uVar1 = *(undefined2 *)(local_30 + 0x10);
    *(undefined2 *)(in_ECX + 0xe2) = uVar1;
    if ((in_ECX[0x57] != 0) && (in_ECX[0xdc] != 0)) {
      FUN_007a6ea0(in_ECX[0x57],1,uVar1);
    }
    if ((in_ECX[0x57] != 0) && (in_ECX[0xdc] != 0)) {
      FUN_007a6830(0);
    }
  }
  if (in_ECX[0x108] == 5) {
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
    iVar3 = in_ECX[1];
    uVar4 = (**(code **)(*in_ECX + 0x50))(local_2c);
    FUN_00551b80(0,2);
    FUN_00551dd0(&DAT_00fdf680,(short)iVar3,uVar4,0,0x3f800000,1);
  }
  else if (in_ECX[0x108] == 7) {
    if ((in_ECX[0x57] == 0) || (in_ECX[0xdc] == 0)) {
      local_20 = in_ECX[0x28];
      local_1c = in_ECX[0x29];
      local_18 = in_ECX[0x2a];
    }
    else {
      FUN_007a8630(0);
    }
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 2;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
    iVar3 = FUN_00551f90((short)in_ECX[1],0,0x3f800000);
    in_ECX[0x109] = iVar3;
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  local_30 = in_ECX[0x22];
  iVar3 = FUN_004f7a70();
  puVar5 = (undefined4 *)(iVar3 + 0x1c);
  if (7 < *(uint *)(iVar3 + 0x30)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  FUN_004d16e0(&DAT_00c0c958,puVar5);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

