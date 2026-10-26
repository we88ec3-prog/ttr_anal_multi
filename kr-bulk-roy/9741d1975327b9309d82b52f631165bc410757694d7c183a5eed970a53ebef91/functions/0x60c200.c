
void FUN_0060c200(int param_1,char param_2,ushort *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int *in_ECX;
  ushort *puVar4;
  bool bVar5;
  
  if ((in_ECX[0x92] == param_1) && ((char)in_ECX[0x93] == param_2)) {
    puVar2 = (ushort *)(in_ECX + 0x98);
    puVar4 = param_3;
    if (7 < (uint)in_ECX[0x9d]) {
      puVar2 = *(ushort **)puVar2;
    }
    do {
      uVar1 = *puVar2;
      bVar5 = uVar1 < *puVar4;
      if (uVar1 != *puVar4) {
LAB_0060c25a:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0060c25f;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar2[1];
      bVar5 = uVar1 < puVar4[1];
      if (uVar1 != puVar4[1]) goto LAB_0060c25a;
      puVar2 = puVar2 + 2;
      puVar4 = puVar4 + 2;
    } while (uVar1 != 0);
    iVar3 = 0;
LAB_0060c25f:
    if (iVar3 == 0) {
      return;
    }
  }
  in_ECX[0x92] = param_1;
  *(char *)(in_ECX + 0x93) = param_2;
  *(undefined2 *)(in_ECX + 0x95) = 0xffff;
  FUN_0060bc90();
  FUN_00757710();
  FUN_0060c2e0();
  (**(code **)(*in_ECX + 200))();
  puVar2 = param_3;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  } while (uVar1 != 0);
  FUN_00402160(param_3,(int)puVar2 - (int)(param_3 + 1) >> 1);
  return;
}

