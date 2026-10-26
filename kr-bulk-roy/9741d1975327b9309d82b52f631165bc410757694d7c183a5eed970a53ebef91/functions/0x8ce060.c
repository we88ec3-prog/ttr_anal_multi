
void FUN_008ce060(undefined4 param_1)

{
  uint uVar1;
  uint *in_EAX;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint local_8;
  
  pbVar2 = (byte *)in_EAX[2];
  uVar1 = *in_EAX;
  uVar4 = 0;
  uVar3 = 0;
  local_8 = 0;
  if (uVar1 != 0) {
    do {
      if (uVar3 == 0) {
        local_8 = (uint)*pbVar2;
        pbVar2 = pbVar2 + 1;
        uVar3 = 0x80;
      }
      if ((local_8 & uVar3) != 0) {
        FUN_008cdfe0(param_1);
      }
      uVar4 = uVar4 + 1;
      uVar3 = (int)uVar3 >> 1;
    } while (uVar4 < uVar1);
  }
  return;
}

