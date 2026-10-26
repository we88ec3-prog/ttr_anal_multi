
bool FUN_00442930(uint *param_1)

{
  code *pcVar1;
  bool bVar2;
  uint *in_EAX;
  int *unaff_ESI;
  
  if ((*in_EAX < *param_1) || (*param_1 == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  FUN_007598b0(1);
  FUN_007598b0(0);
  pcVar1 = *(code **)(*unaff_ESI + 200);
  unaff_ESI[0x55] = (-(uint)bVar2 & 0xfe0100) - 0xff0100;
  (*pcVar1)();
  return !bVar2;
}

