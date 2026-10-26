
void FUN_00651880(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  undefined **local_30 [3];
  char *local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f68f;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1 = (int *)((int)param_1 + 0xf8);
  local_14 = 0;
  do {
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x25c) != 0) {
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 0;
        DAT_00f8d9b4 = 0;
        iVar5 = FUN_00891268(0x18,uVar4);
        if (iVar5 == 0) {
          local_24 = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_24);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        DAT_00f8d9b0 = iVar5;
        *(int *)iVar5 = iVar5;
        *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
        *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
        *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      local_18 = *(undefined4 *)(iVar2 + 0x250);
      FUN_008438c0(&local_18);
      if ((local_1c == DAT_00f8d9b0) || (*(int *)(local_1c + 0x10) == 0)) {
LAB_00651a5c:
        iVar5 = *(int *)(iVar2 + 0x2a0);
        if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
           (iVar7 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar7 == 0xbf6b)) {
          iVar5 = *(int *)(iVar5 + 0x94);
          iVar7 = *(int *)(iVar5 + 0x10);
          if (iVar7 != 0) {
            piVar3 = *(int **)(iVar7 + 8);
            if (piVar3 != (int *)0x0) {
              piVar1 = piVar3 + 0x27;
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                (**(code **)(*piVar3 + 0x28))();
              }
            }
            *(undefined4 *)(iVar5 + 0x10) = 0;
          }
        }
      }
      else {
        if ((DAT_00fb744c & 1) == 0) {
          DAT_00fb744c = DAT_00fb744c | 1;
          local_8 = 2;
          FUN_004eec60();
          _atexit(FUN_00bcd140);
          local_8 = 0xffffffff;
        }
        puVar6 = (ushort *)FUN_004eeb00();
        if (puVar6 == (ushort *)0x0) goto LAB_00651a5c;
        if ((DAT_00f94394 & 1) == 0) {
          DAT_00f94394 = DAT_00f94394 | 1;
          local_8 = 3;
          FUN_005c3de0();
          _atexit((_func_4879 *)&LAB_00bccc30);
          local_8 = 0xffffffff;
        }
        local_20 = (uint)*puVar6;
        local_18 = (undefined4)((ulonglong)puVar6[1] % (ulonglong)(longlong)(int)local_20);
        FUN_008fed10();
        iVar5 = *(int *)(iVar2 + 0x2a0);
        if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
           (iVar5 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
          FUN_0077b200();
        }
      }
      (**(code **)(**(int **)(iVar2 + 0x2a0) + 200))();
    }
    param_1 = param_1 + 1;
    local_14 = local_14 + 1;
    if (3 < local_14) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

