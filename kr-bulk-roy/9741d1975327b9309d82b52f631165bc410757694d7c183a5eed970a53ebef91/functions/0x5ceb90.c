
undefined4 FUN_005ceb90(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined **local_2c [3];
  char *local_20;
  int local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929081;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x3f8) != 0) {
    local_14 = **(int **)(param_1 + 0x3f4);
    if ((int *)local_14 != *(int **)(param_1 + 0x3f4)) {
      do {
        iVar4 = local_14;
        if ((DAT_00fe699c & 1) == 0) {
          DAT_00fe699c = DAT_00fe699c | 1;
          local_8 = 0;
          DAT_00fe3718 = 0;
          iVar3 = FUN_00891268(0x18,uVar2);
          if (iVar3 == 0) {
            local_20 = (char *)0x0;
            std::exception::exception((exception *)local_2c,&local_20);
            local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_2c,&DAT_00c857a8);
          }
          DAT_00fe3714 = iVar3;
          *(int *)iVar3 = iVar3;
          *(int *)(DAT_00fe3714 + 4) = DAT_00fe3714;
          *(int *)(DAT_00fe3714 + 8) = DAT_00fe3714;
          *(undefined1 *)(DAT_00fe3714 + 0x14) = 1;
          *(undefined1 *)(DAT_00fe3714 + 0x15) = 1;
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_005112a0();
          _atexit(FUN_00bcf750);
          local_8 = 0xffffffff;
        }
        local_18 = (uint)*(ushort *)(iVar4 + 0x10);
        FUN_008438c0(&local_18);
        if (local_1c == DAT_00fe3714) {
          cVar1 = -1;
        }
        else {
          cVar1 = *(char *)(local_1c + 0x10);
        }
        if ((DAT_00fc1094 & 1) == 0) {
          DAT_00fc1094 = DAT_00fc1094 | 1;
          local_8 = 2;
          FUN_0052f7e0();
          _atexit((_func_4879 *)&LAB_00bcdc80);
          local_8 = 0xffffffff;
        }
        iVar4 = FUN_00530330();
        if ((cVar1 == iVar4) || (cVar1 == 0)) {
          ExceptionList = local_10;
          return 1;
        }
        FUN_0049e6a0();
      } while (local_14 != *(int *)(param_1 + 0x3f4));
    }
  }
  ExceptionList = local_10;
  return 0;
}

