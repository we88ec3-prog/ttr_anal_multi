
int FUN_008d8df0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *unaff_EBX;
  
  iVar2 = *(int *)(in_EAX + 0x1c);
  if (*(char *)(in_EAX + 0x20) == '\0') {
    return 8;
  }
  if ((*(uint *)(iVar2 + 4) < (uint)(*(short *)(iVar2 + 0x3a) + 3 + (int)*(short *)(iVar2 + 0x16)))
     && (iVar3 = FUN_008bc9a0(iVar2,3,0), iVar3 != 0)) {
    return iVar3;
  }
  puVar1 = (undefined4 *)(*(int *)(iVar2 + 0x3c) + *(short *)(iVar2 + 0x3a) * 8);
  puVar4 = (undefined2 *)(*(int *)(iVar2 + 0x40) + (int)*(short *)(iVar2 + 0x3a));
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = *param_2;
  puVar1[3] = param_2[1];
  puVar1[4] = *unaff_EBX;
  puVar1[5] = unaff_EBX[1];
  *puVar4 = 0x202;
  *(undefined1 *)(puVar4 + 1) = 1;
  *(short *)(iVar2 + 0x3a) = *(short *)(iVar2 + 0x3a) + 3;
  return 0;
}

