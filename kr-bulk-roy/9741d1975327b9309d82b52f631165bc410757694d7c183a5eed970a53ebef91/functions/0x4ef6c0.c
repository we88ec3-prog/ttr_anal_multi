
undefined4 FUN_004ef6c0(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  short *psVar4;
  int in_ECX;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933c7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(200,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_004ef0d0();
  }
  *puVar3 = *(undefined4 *)(in_ECX + 2);
  puVar3[1] = *(undefined4 *)(in_ECX + 6);
  local_14 = in_ECX + 0xc;
  psVar4 = (short *)(in_ECX + 10);
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  local_18 = puVar3;
  FUN_00402160((short *)(in_ECX + 10),(int)psVar4 - local_14 >> 1);
  local_14 = in_ECX + 0x36;
  psVar4 = (short *)(in_ECX + 0x34);
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160((short *)(in_ECX + 0x34),(int)psVar4 - local_14 >> 1);
  *(undefined2 *)(puVar3 + 0x18) = *(undefined2 *)(in_ECX + 0x5e);
  *(undefined1 *)((int)puVar3 + 0x62) = *(undefined1 *)(in_ECX + 0x60);
  *(undefined1 *)((int)puVar3 + 99) = *(undefined1 *)(in_ECX + 0x61);
  *(undefined1 *)(puVar3 + 9) = 0;
  FUN_004ef080();
  FUN_004ef080();
  FUN_004f07f0(&local_18);
  FUN_004ef210(param_1);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4270);
  ExceptionList = local_10;
  return 0;
}

