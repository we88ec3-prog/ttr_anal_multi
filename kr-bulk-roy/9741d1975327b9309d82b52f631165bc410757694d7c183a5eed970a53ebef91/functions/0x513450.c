
void FUN_00513450(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *in_ECX;
  undefined4 *puVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d3e8;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)in_ECX[2];
  *in_ECX = CDialogTable::vftable;
  puVar4 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar7 = puVar4;
          if (puVar7 == puVar2) {
            local_8 = 0;
            FUN_005540c0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
            FUN_0089120c(in_ECX[2]);
            ExceptionList = local_10;
            return;
          }
          piVar3 = (int *)puVar7[4];
          if (piVar3 != (int *)0x0) {
            if (*piVar3 != 0) {
              FUN_00513de0(in_ECX,uVar5);
              FUN_0089120c(*piVar3);
            }
            *piVar3 = 0;
            piVar3[1] = 0;
            piVar3[2] = 0;
            FUN_0089120c(piVar3);
          }
          puVar4 = puVar7;
        } while (*(char *)((int)puVar7 + 0x15) != '\0');
        puVar4 = (undefined4 *)puVar7[2];
        if (*(char *)((int)puVar4 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar7 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x15);
          puVar4 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      puVar4 = (undefined4 *)puVar7[1];
    } while (*(char *)((int)puVar4 + 0x15) != '\0');
    do {
      puVar6 = puVar4;
      puVar4 = puVar6;
      if (puVar7 != (undefined4 *)puVar6[2]) break;
      puVar4 = (undefined4 *)puVar6[1];
      puVar7 = puVar6;
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  } while( true );
}

