
void FUN_00757da0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 in_EAX;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_00448090(unaff_ESI,in_EAX,unaff_EDI);
  puVar2 = *(undefined4 **)(param_1 + 0x2c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (unaff_ESI < (int)puVar3[4]) {
      puVar3[4] = puVar3[4] + unaff_EDI;
    }
    if (unaff_ESI < (int)puVar3[5]) {
      puVar3[5] = puVar3[5] + unaff_EDI;
    }
    if (*(char *)((int)puVar3 + 0x21) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x21);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x21);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    if (unaff_ESI <= (int)puVar3[2]) {
      puVar3[2] = puVar3[2] + unaff_EDI;
    }
  }
  return;
}

