
int FUN_008ea700(int param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  sbyte sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_8;
  
  iVar1 = (**(code **)(in_EAX + 0x1fc))();
  if ((char)iVar1 == -0x72) {
    *(undefined4 *)(in_EAX + 0x29c) = 0;
  }
  else if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(in_EAX + 0x1fc))();
  if (iVar1 == 0) {
    if (*(short *)(in_EAX + 0xd2) == 0) {
      sVar4 = 1;
      if (0x1ffff < local_8) {
        return 8;
      }
      uVar2 = local_8 >> 1;
    }
    else {
      sVar4 = 2;
      if (0x3ffff < local_8) {
        return 8;
      }
      uVar2 = local_8 >> 2;
    }
    *(uint *)(in_EAX + 0x2b8) = uVar2;
    uVar2 = *(uint *)(in_EAX + 0x10) + 1;
    if ((*(uint *)(in_EAX + 0x2b8) != uVar2) &&
       (*(uint *)(in_EAX + 0x2b8) <= *(uint *)(in_EAX + 0x10))) {
      uVar6 = *(uint *)(in_EAX + 0x9c);
      uVar2 = uVar2 << sVar4;
      uVar7 = (uint)*(ushort *)(in_EAX + 0x98) * 0x10 + uVar6;
      iVar3 = FUN_008b9850(param_1);
      iVar1 = 0x7fffffff;
      for (; uVar6 < uVar7; uVar6 = uVar6 + 0x10) {
        iVar5 = *(int *)(uVar6 + 8) - iVar3;
        if ((0 < iVar5) && (iVar5 < iVar1)) {
          iVar1 = iVar5;
        }
      }
      if (uVar6 == uVar7) {
        iVar1 = *(int *)(param_1 + 4) - iVar3;
      }
      if ((int)uVar2 <= iVar1) {
        *(int *)(in_EAX + 0x2b8) = *(int *)(in_EAX + 0x10) + 1;
        local_8 = uVar2;
      }
    }
    iVar1 = FUN_008bc7a0(param_1,local_8,in_EAX + 700);
    return iVar1;
  }
  return 0x90;
}

