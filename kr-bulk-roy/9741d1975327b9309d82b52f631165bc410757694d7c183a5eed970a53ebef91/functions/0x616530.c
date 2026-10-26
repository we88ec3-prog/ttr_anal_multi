
void FUN_00616530(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_00744ca0(param_1);
  iVar6 = *(int *)(param_1 + 0x10);
  if (iVar6 == 0xcb) {
    iVar6 = in_ECX[0x98];
    iVar5 = in_ECX[0x97];
    uVar3 = (uint)*(byte *)(in_ECX + 0x94);
    iVar1 = *in_ECX;
    iVar4 = in_ECX[0x92];
    FUN_0046fee0(iVar4,uVar3,iVar5,iVar6);
    uVar2 = FUN_0060c740(iVar4,uVar3,iVar5,iVar6);
    (**(code **)(iVar1 + 0x50))(uVar2);
    return;
  }
  if (iVar6 == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
    return;
  }
  if ((iVar6 == 200) && ((char)in_ECX[0x96] != '\0')) {
    (**(code **)(*in_ECX + 0x54))();
    iVar6 = in_ECX[0x98];
    iVar5 = in_ECX[0x97];
    uVar3 = (uint)*(byte *)(in_ECX + 0x94);
    iVar1 = *in_ECX;
    iVar4 = in_ECX[0x92];
    FUN_0046fee0(iVar4,uVar3,iVar5,iVar6);
    uVar2 = FUN_0060c740(iVar4,uVar3,iVar5,iVar6);
    (**(code **)(iVar1 + 0x50))(uVar2);
    *(undefined1 *)(in_ECX + 0x96) = 0;
  }
  return;
}

