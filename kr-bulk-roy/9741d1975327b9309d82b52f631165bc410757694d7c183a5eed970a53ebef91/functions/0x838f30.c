
undefined4 FUN_00838f30(uint param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int in_EAX;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  uVar3 = param_1;
  iVar1 = *(int *)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) * 4);
  if (((uint)(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10)) < param_1) &&
     (iVar1 = *(int *)(in_EAX + 0x14) + 1, *(int *)(in_EAX + 0x14) = iVar1,
     iVar1 == *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2)) {
    uVar4 = *(uint *)(in_EAX + 0x5c);
    if (*(uint *)(in_EAX + 0x5c) < param_1) {
      uVar4 = param_1;
    }
    FUN_00839220(uVar4);
  }
  puVar2 = *(uint **)(in_EAX + 0x1c);
  puVar5 = *(uint **)(in_EAX + 0x18);
  if (puVar2 != puVar5) {
    do {
      if (*puVar5 == *param_2) break;
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar2);
    if (puVar2 != puVar5) {
      puVar6 = (undefined4 *)FUN_0083fc50(in_EAX + 0x28,*param_2);
      goto LAB_00838fbe;
    }
  }
  param_1 = 0;
  puVar6 = (undefined4 *)FUN_0083fb70(in_EAX + 0x28,&param_1);
  *param_2 = param_1;
LAB_00838fbe:
  *puVar6 = *(undefined4 *)(in_EAX + 0x14);
  puVar6[2] = uVar3;
  uVar7 = (**(code **)(**(int **)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) * 4) + 4))
                    (uVar3,puVar6 + 1);
  FUN_0083eab0();
  return uVar7;
}

