
void FUN_0077e800(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  float *unaff_ESI;
  undefined4 *unaff_EDI;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  local_28 = *in_EAX;
  local_24 = in_EAX[1];
  local_20 = in_EAX[2];
  local_38 = -*unaff_ESI;
  local_34 = -unaff_ESI[1];
  local_30 = -unaff_ESI[2];
  local_2c = unaff_ESI[3];
  uVar1 = FUN_0077e880(&local_38);
  FUN_0077e880(uVar1);
  *unaff_EDI = local_28;
  unaff_EDI[1] = local_24;
  unaff_EDI[2] = local_20;
  return;
}

