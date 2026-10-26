
int FUN_00436b70(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941a9e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_004b0640(param_1,param_2,param_3);
  if (iVar2 == 0) {
    if (param_2 < 2) {
      uVar3 = 0;
    }
    else {
      uVar3 = (param_2 - 2) / 0xd;
    }
    if (uVar3 != 0) {
      puVar4 = (undefined2 *)(param_1 + 4);
      do {
        if ((*(char *)(puVar4 + 1) == '\0') || ((byte)(*(char *)(puVar4 + 1) - 2U) < 2)) {
          if ((DAT_00fb7a20 & 1) == 0) {
            DAT_00fb7a20 = DAT_00fb7a20 | 1;
            local_8 = 0;
            FUN_00548da0(uVar1);
            _atexit(FUN_00bcd370);
            local_8 = 0xffffffff;
          }
          FUN_0054a8f0(puVar4[-1],*puVar4);
        }
        puVar4 = (undefined2 *)((int)puVar4 + 0xd);
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  ExceptionList = local_10;
  return iVar2;
}

