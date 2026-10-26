
void FUN_0053ff50(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *unaff_EDI;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094784a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  if ((DAT_00fb73e8 == 0) && (local_20 = unaff_EDI[1] - *unaff_EDI >> 4, local_20 != 0)) {
    iVar5 = 0;
    do {
      iVar2 = *(int *)(*unaff_EDI + 0xc + iVar5);
      iVar6 = *unaff_EDI + iVar5;
      if (iVar2 == 0) {
        FUN_0089289d();
        iVar2 = FUN_008fed10();
        *(int *)(iVar6 + 0xc) = (unaff_EDI[8] - unaff_EDI[9] / 2) + iVar2;
        FUN_0089289d();
        iVar2 = FUN_008fed10();
        if ((float)unaff_EDI[10] <= (float)iVar2 / 1023.0) {
          if ((DAT_00fab29c & 1) == 0) {
            DAT_00fab29c = DAT_00fab29c | 1;
            local_c = 1;
            FUN_004ffe60();
            _atexit((_func_4879 *)&LAB_00bccf00);
            local_c = 0xffffffff;
          }
          uVar3 = FUN_00500a80(&DAT_00fab2a0,*(undefined4 *)(iVar6 + 4));
          switch(uVar3) {
          case 0:
            piVar1 = *(int **)(iVar6 + 8);
            if ((piVar1[1] - *piVar1 & 0xfffffffcU) != 0) {
              iVar2 = FUN_0053ff20(piVar1[1] - *piVar1 >> 2);
              uVar3 = *(undefined4 *)(**(int **)(iVar6 + 8) + iVar2 * 4);
LAB_00540171:
              iVar2 = FUN_00527040(uVar3);
              if (iVar2 != 0) {
                if (*(uint *)(iVar2 + 0x18) < 8) {
                  iVar2 = iVar2 + 4;
                }
                else {
                  iVar2 = *(int *)(iVar2 + 4);
                }
                if ((DAT_00fd8ea8 & 1) == 0) {
                  DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
                  local_c = 2;
                  FUN_0055ac10();
                  _atexit((_func_4879 *)&LAB_00bcdfe0);
                  local_c = 0xffffffff;
                }
                FUN_0055ae70(&DAT_00fd8eb0,iVar2,0);
              }
            }
            break;
          case 1:
          case 2:
          case 4:
            iVar2 = *(int *)(iVar6 + 8);
            if ((*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0x10) & 0xfffffffcU) != 0) {
              iVar4 = FUN_0053ff20(*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0x10) >> 2);
              iVar2 = *(int *)(*(int *)(iVar6 + 8) + 0x10);
LAB_0054016a:
              uVar3 = *(undefined4 *)(iVar2 + iVar4 * 4);
              goto LAB_00540171;
            }
            break;
          case 3:
            iVar2 = *(int *)(iVar6 + 8);
            if ((*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20) & 0xfffffffcU) != 0) {
              iVar4 = FUN_0053ff20(*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20) >> 2);
              iVar2 = *(int *)(*(int *)(iVar6 + 8) + 0x20);
              goto LAB_0054016a;
            }
            break;
          case 5:
            iVar2 = *(int *)(iVar6 + 8);
            if ((*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x30) & 0xfffffffcU) != 0) {
              iVar4 = FUN_0053ff20(*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x30) >> 2);
              iVar2 = *(int *)(*(int *)(iVar6 + 8) + 0x30);
              goto LAB_0054016a;
            }
          }
        }
      }
      else {
        *(int *)(iVar6 + 0xc) = iVar2 + -1;
      }
      iVar5 = iVar5 + 0x10;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  ExceptionList = local_14;
  return;
}

