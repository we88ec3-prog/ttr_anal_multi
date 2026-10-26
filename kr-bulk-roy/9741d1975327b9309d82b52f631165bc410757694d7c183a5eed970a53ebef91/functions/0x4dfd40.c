
void FUN_004dfd40(ushort param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *piVar6;
  undefined1 auStack_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  piVar6 = (int *)**(int **)(in_ECX + 0xc);
  if (piVar6 != *(int **)(in_ECX + 0xc)) {
    do {
      iVar1 = piVar6[4];
      if (*(byte *)(iVar1 + 4) == param_1) {
        if ((iVar1 != 0) &&
           ((((cVar4 = (char)*(undefined2 *)(iVar1 + 4), cVar4 == '\x01' || (cVar4 == '\x06')) ||
             (cVar4 == '\0')) || (cVar4 == '\a')))) {
          local_18 = 0x3f800000;
          local_14 = 0x3f800000;
          local_10 = 0x3f800000;
          local_c = 0x3f800000;
          if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
            FUN_007a7cc0(*(int *)(iVar1 + 0x15c),0);
            FUN_007a7bf0(local_18,local_14,local_10,local_c);
          }
        }
        (**(code **)(*(int *)piVar6[4] + 0x14))();
        if ((undefined4 *)piVar6[4] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar6[4])(1);
          piVar6[4] = 0;
        }
        puVar5 = (undefined4 *)FUN_007b6890(in_ECX + 8,auStack_1c,piVar6);
        piVar6 = (int *)*puVar5;
      }
      else if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar4 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar4 == '\0') {
            cVar4 = *(char *)(*piVar2 + 0x15);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar4 = *(char *)(piVar6[1] + 0x15);
          piVar3 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar3, cVar4 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar4 = *(char *)(piVar6[1] + 0x15);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(in_ECX + 0xc));
  }
  return;
}

