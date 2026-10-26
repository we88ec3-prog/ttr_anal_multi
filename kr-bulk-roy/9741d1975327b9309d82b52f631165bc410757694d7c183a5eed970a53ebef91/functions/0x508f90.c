
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00508f90(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  int iVar5;
  undefined **local_30 [3];
  undefined4 local_24;
  undefined4 local_20;
  char *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094004e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  iVar5 = 1;
  puVar4 = (undefined4 *)(in_ECX + 0x30);
  do {
    if (puVar4[-3] == param_1) {
      if ((DAT_00fab0d8 & 1) == 0) {
        DAT_00fab0d8 = DAT_00fab0d8 | 1;
        local_8 = 0;
        _DAT_00fab0e4 = 0;
        iVar3 = FUN_00891268(0x28,uVar2);
        if (iVar3 == 0) {
          local_1c = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_1c);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        DAT_00fab0e0 = iVar3;
        *(int *)iVar3 = iVar3;
        *(int *)(DAT_00fab0e0 + 4) = DAT_00fab0e0;
        *(int *)(DAT_00fab0e0 + 8) = DAT_00fab0e0;
        *(undefined1 *)(DAT_00fab0e0 + 0x20) = 1;
        *(undefined1 *)(DAT_00fab0e0 + 0x21) = 1;
        DAT_00fab0ec = 0;
        _DAT_00fab0f0 = 0;
        _DAT_00fab0f4 = 0;
        _atexit((_func_4879 *)&LAB_00bccdb0);
        local_8 = 0xffffffff;
      }
      local_24 = *puVar4;
      local_20 = puVar4[1];
      FUN_004dd400(&DAT_00fab0dc,&local_18,&local_24);
      if (((local_18 == DAT_00fab0e0) || (*(int *)(local_18 + 0x18) == 0)) ||
         (*(char *)(*(int *)(local_18 + 0x18) + 0x15) == '\0')) {
        cVar1 = FUN_00509130(puVar4[-1]);
        if (cVar1 != '\0') {
          local_14 = local_14 + puVar4[-2];
        }
      }
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 8;
  } while (iVar5 < 0x65);
  ExceptionList = local_10;
  return local_14;
}

