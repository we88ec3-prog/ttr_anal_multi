
undefined4 * FUN_0052e170(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_8;
  
  puVar5 = param_2;
  puVar7 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar7 + 0x29);
  bVar8 = true;
  local_8 = 1;
  puVar4 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    uVar2 = puVar7[5];
    if (*(uint *)(in_EAX + 0x10) == puVar7[4]) {
      uVar3 = *(uint *)(in_EAX + 0x14);
      bVar8 = uVar3 == uVar2;
      if (!bVar8) goto LAB_0052e203;
      if ((*(uint *)(in_EAX + 0x1c) <= (uint)puVar7[7]) &&
         ((*(uint *)(in_EAX + 0x1c) < (uint)puVar7[7] ||
          (*(uint *)(in_EAX + 0x18) < (uint)puVar7[6])))) goto LAB_0052e20c;
LAB_0052e1be:
      puVar6 = (undefined4 *)puVar7[2];
      bVar8 = false;
      local_8 = 0;
    }
    else {
      uVar3 = *(uint *)(in_EAX + 0x14);
      bVar8 = uVar3 == uVar2;
LAB_0052e203:
      if ((uVar2 <= uVar3 && !bVar8) ||
         ((uVar2 <= uVar3 && ((uint)puVar7[4] <= *(uint *)(in_EAX + 0x10))))) goto LAB_0052e1be;
LAB_0052e20c:
      puVar6 = (undefined4 *)*puVar7;
      bVar8 = true;
      local_8 = 1;
    }
    puVar4 = puVar7;
    puVar7 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0x29);
  }
  if (bVar8) {
    if (puVar4 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar7 = (undefined4 *)FUN_0052e6f0(&param_2,1,in_EAX);
      *puVar5 = *puVar7;
      *(undefined1 *)(puVar5 + 1) = 1;
      return puVar5;
    }
    FUN_00827b40();
  }
  uVar2 = puVar4[5];
  uVar3 = *(uint *)(in_EAX + 0x14);
  if ((puVar4[4] == *(uint *)(in_EAX + 0x10)) && (uVar2 == uVar3)) {
    if (((uint)puVar4[7] < *(uint *)(in_EAX + 0x1c)) ||
       ((puVar4[7] == *(uint *)(in_EAX + 0x1c) && ((uint)puVar4[6] < *(uint *)(in_EAX + 0x18))))) {
LAB_0052e26b:
      puVar7 = (undefined4 *)FUN_0052e6f0(&param_1,local_8,in_EAX);
      *param_2 = *puVar7;
      *(undefined1 *)(param_2 + 1) = 1;
      return param_2;
    }
  }
  else if ((uVar2 <= uVar3) && ((uVar2 < uVar3 || ((uint)puVar4[4] < *(uint *)(in_EAX + 0x10)))))
  goto LAB_0052e26b;
  FUN_0089120c();
  *param_2 = puVar4;
  *(undefined1 *)(param_2 + 1) = 0;
  return param_2;
}

