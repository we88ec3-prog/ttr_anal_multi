
void FUN_00817be0(void)

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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090736b;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar7 = (int *)*DAT_00fb11b0;
  piVar6 = DAT_00fb11b0;
  if (piVar7 != DAT_00fb11b0) {
    do {
      iVar2 = piVar7[4];
      if (iVar2 != 0) {
        piVar6 = (int *)(iVar2 + 0x14);
        local_8 = 0;
        FUN_0081b110(piVar6,uVar5);
        local_8 = 0xffffffff;
        if (*piVar6 != 0) {
          FUN_0089120c(*piVar6);
        }
        *piVar6 = 0;
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        FUN_0089120c(iVar2);
        piVar6 = DAT_00fb11b0;
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
  FUN_00817b80();
  ExceptionList = local_10;
  return;
}

