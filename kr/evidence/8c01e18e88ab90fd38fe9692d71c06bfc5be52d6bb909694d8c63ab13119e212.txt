
void FUN_004aa070(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009397e7;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  local_20 = 3;
  FUN_004aa530(&local_20);
  iVar2 = local_1c;
  if ((local_1c != *(int *)(in_ECX + 0x28)) && (local_1c != -0x10)) {
    local_1c = FUN_00891268(0x420,uVar3);
    local_c = 0;
    if (local_1c == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_004c7070(local_1c);
    }
    local_c = 0xffffffff;
    local_20 = CONCAT22((short)((uint)local_20 >> 0x10),0xf000);
    *(undefined2 *)(piVar4 + 1) = 0xf000;
    pcVar1 = *(code **)(*piVar4 + 0x3c);
    piVar4[0x24] = 0x10;
    (*pcVar1)(4);
    (**(code **)(*piVar4 + 0x44))(iVar2 + 0x14,1);
    (**(code **)(*piVar4 + 0x58))(0);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_1c = 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_1c = -1;
    }
    (**(code **)(*piVar4 + 0x5c))(DAT_00fb90bc * 12.0);
    *(undefined2 *)(piVar4 + 0xe2) = 1;
    if ((piVar4[0x57] != 0) && (piVar4[0xdc] != 0)) {
      FUN_007a6ea0(piVar4[0x57],1,1);
    }
    (**(code **)(*piVar4 + 0x30))();
    (**(code **)(piVar4[0x3c] + 8))(0x14);
    (**(code **)(*piVar4 + 0x68))(1,0x3f800000);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    FUN_004dff30(&DAT_00fab130);
  }
  ExceptionList = local_14;
  return;
}

