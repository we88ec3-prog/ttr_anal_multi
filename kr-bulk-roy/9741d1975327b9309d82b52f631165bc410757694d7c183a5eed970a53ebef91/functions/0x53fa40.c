
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053fa40(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009083dd;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar7 = (int *)*DAT_00fe18e0;
  piVar6 = DAT_00fe18e0;
  if (piVar7 != DAT_00fe18e0) {
    do {
      iVar2 = piVar7[4];
      if (iVar2 != 0) {
        FUN_0053fb40(uVar5);
        FUN_0089120c(iVar2);
        piVar7[4] = 0;
        piVar6 = DAT_00fe18e0;
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar6);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_005540c0(*piVar6,piVar6);
  FUN_0089120c(DAT_00fe18e0);
  if (DAT_00fe18cc != 0) {
    FUN_0089120c(DAT_00fe18cc);
  }
  DAT_00fe18cc = 0;
  DAT_00fe18d0 = 0;
  _DAT_00fe18d4 = 0;
  ExceptionList = local_10;
  return;
}

