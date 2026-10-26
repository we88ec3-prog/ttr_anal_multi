
undefined4 FUN_004f6dc0(ushort *param_1)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  bool bVar9;
  
  puVar3 = (undefined4 *)**(undefined4 **)(in_EAX + 0x104);
  do {
    if (puVar3 == *(undefined4 **)(in_EAX + 0x104)) {
      return 0xffffffff;
    }
    puVar6 = (ushort *)puVar3[4];
    puVar8 = param_1;
    if (7 < *(uint *)(puVar6 + 10)) {
      puVar6 = *(ushort **)puVar6;
    }
    do {
      uVar2 = *puVar6;
      bVar9 = uVar2 < *puVar8;
      if (uVar2 != *puVar8) {
LAB_004f6e16:
        iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_004f6e1b;
      }
      if (uVar2 == 0) break;
      uVar2 = puVar6[1];
      bVar9 = uVar2 < puVar8[1];
      if (uVar2 != puVar8[1]) goto LAB_004f6e16;
      puVar6 = puVar6 + 2;
      puVar8 = puVar8 + 2;
    } while (uVar2 != 0);
    iVar7 = 0;
LAB_004f6e1b:
    if (iVar7 == 0) {
      return puVar3[3];
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  } while( true );
}

