
undefined4 FUN_004b2620(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint local_10;
  
  DAT_00fba7a4[1] = 0;
  iVar5 = FUN_0040f060();
  piVar7 = (int *)**(int **)(iVar5 + 0xc);
  if (piVar7 != *(int **)(iVar5 + 0xc)) {
    do {
      piVar1 = (int *)piVar7[4];
      cVar4 = (char)(short)piVar1[1];
      if ((cVar4 == '\0') || (cVar4 == '\x01')) {
        piVar6 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
        if (piVar1 == piVar6) {
          DAT_00fba7a4[0x1d] = 0;
        }
        (**(code **)(piVar1[0x3c] + 8))(1);
        iVar3 = piVar1[0x39];
        local_10 = piVar1[0x38] & 0x7fffffff;
        (**(code **)(*DAT_00fba7a4 + 0x20))();
        pcVar2 = *(code **)(*piVar1 + 0x58);
        piVar1[0x38] = local_10;
        *(char *)(piVar1 + 0x39) = (char)iVar3;
        (*pcVar2)((char)iVar3);
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar1 = (int *)piVar7[2];
        if (*(char *)((int)piVar1 + 0x15) == '\0') {
          cVar4 = *(char *)(*piVar1 + 0x15);
          piVar7 = piVar1;
          piVar1 = (int *)*piVar1;
          while (cVar4 == '\0') {
            cVar4 = *(char *)(*piVar1 + 0x15);
            piVar7 = piVar1;
            piVar1 = (int *)*piVar1;
          }
        }
        else {
          cVar4 = *(char *)(piVar7[1] + 0x15);
          piVar6 = (int *)piVar7[1];
          piVar1 = piVar7;
          while ((piVar7 = piVar6, cVar4 == '\0' && (piVar1 == (int *)piVar7[2]))) {
            cVar4 = *(char *)(piVar7[1] + 0x15);
            piVar6 = (int *)piVar7[1];
            piVar1 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(iVar5 + 0xc));
  }
  return 0;
}

