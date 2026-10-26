
uint * FUN_0071a4c0(int param_1)

{
  uint uVar1;
  uint *in_EAX;
  uint *puVar2;
  uint local_8;
  
  uVar1 = in_EAX[1] + 0x20;
  if (uVar1 < 0x8001) {
    local_8 = *in_EAX;
    puVar2 = (uint *)(local_8 + 0x18 + in_EAX[1]);
    in_EAX[1] = uVar1;
  }
  else {
    puVar2 = (uint *)FUN_0071a440(&local_8);
  }
  if (puVar2 != (uint *)0x0) {
    *puVar2 = param_1 - 1U | local_8;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    return puVar2;
  }
  return (uint *)0x0;
}

