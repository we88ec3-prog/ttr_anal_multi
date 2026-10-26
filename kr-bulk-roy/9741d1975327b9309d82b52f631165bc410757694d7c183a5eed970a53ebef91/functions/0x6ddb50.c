
bool FUN_006ddb50(void)

{
  uint uVar1;
  uint uVar2;
  int in_EAX;
  uint uVar3;
  int in_EDX;
  
  uVar1 = *(uint *)(in_EAX + 0x10);
  uVar2 = *(uint *)(in_EDX + 0x10);
  uVar3 = uVar2;
  if (uVar1 <= uVar2) {
    uVar3 = uVar1;
  }
  uVar3 = FUN_00407e70(uVar3);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return false;
    }
    uVar3 = (uint)(uVar2 != uVar1);
  }
  return uVar3 == 0;
}

