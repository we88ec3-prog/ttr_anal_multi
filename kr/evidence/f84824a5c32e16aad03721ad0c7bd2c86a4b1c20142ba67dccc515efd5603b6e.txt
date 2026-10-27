
uint FUN_00546780(undefined4 param_1,undefined1 *param_2,ushort *param_3)

{
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9 [5];
  
  uVar1 = *param_2;
  uVar6 = *(ushort *)(in_EAX + 0x5c);
  iVar2 = FUN_00547240();
  if (iVar2 != 0) {
    if (iVar2 == 2) {
      uVar6 = uVar6 | 8;
    }
    else if (iVar2 == 3) {
      uVar6 = uVar6 | 0x80;
    }
    else if (iVar2 == 4) {
      uVar6 = uVar6 | 0x40;
    }
  }
  uVar3 = FUN_00546850(&local_b);
  uVar4 = FUN_00546b50(param_1,&local_a,uVar3);
  uVar5 = FUN_00546d50(local_9);
  *param_3 = uVar6;
  if (uVar3 != 0) {
    *param_2 = uVar1;
    return uVar5 | uVar4 | uVar3;
  }
  if (uVar4 != 0) {
    *param_2 = uVar1;
    return uVar5 | uVar4;
  }
  if (uVar5 != 0) {
    *param_2 = uVar1;
  }
  return uVar5;
}

