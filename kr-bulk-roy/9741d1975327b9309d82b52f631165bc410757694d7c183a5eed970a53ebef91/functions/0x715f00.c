
void FUN_00715f00(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cb1a;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar7 = (int *)*DAT_00fe1e00;
  piVar6 = DAT_00fe1e00;
  if (piVar7 != DAT_00fe1e00) {
    do {
      puVar2 = (undefined4 *)piVar7[10];
      if (puVar2 != (undefined4 *)0x0) {
        FUN_00718dd0(uVar5);
        if (0xf < (uint)puVar2[0xc]) {
          FUN_0089120c(puVar2[7]);
        }
        puVar2[0xc] = 0xf;
        puVar2[0xb] = 0;
        *(undefined1 *)(puVar2 + 7) = 0;
        if (0xf < (uint)puVar2[5]) {
          FUN_0089120c(*puVar2);
        }
        puVar2[5] = 0xf;
        puVar2[4] = 0;
        *(undefined1 *)puVar2 = 0;
        FUN_0089120c(puVar2);
        piVar6 = DAT_00fe1e00;
      }
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x2d);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x2d);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar6);
  }
  FUN_007b7d40(piVar6[1]);
  DAT_00fe1e00[1] = (int)DAT_00fe1e00;
  *DAT_00fe1e00 = (int)DAT_00fe1e00;
  DAT_00fe1e00[2] = (int)DAT_00fe1e00;
  DAT_00fe1e04 = 0;
  local_8 = 1;
  FUN_00716c70(*DAT_00fe1e00,DAT_00fe1e00);
  FUN_0089120c(DAT_00fe1e00);
  ExceptionList = local_10;
  return;
}

