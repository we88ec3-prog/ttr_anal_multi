
void FUN_007d4480(void)

{
  int in_EAX;
  float *unaff_ESI;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(int *)(in_EAX + 0x18) != 0) {
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_14 = 1;
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    local_18 = 0x3f800000;
    FUN_007c6880(*(undefined4 *)(in_EAX + 0x10),&DAT_00c4fde8,&local_3c);
    FUN_007cd220();
    *unaff_ESI = local_4c + local_58 * 0.0 + local_64 * 0.0 + local_70 * 0.0;
    unaff_ESI[1] = local_54 * 0.0 + local_60 * 0.0 + local_6c * 0.0 + local_48;
    unaff_ESI[2] = local_5c * 0.0 + local_68 * 0.0 + local_50 * 0.0 + local_44;
    return;
  }
  *unaff_ESI = 0.0;
  unaff_ESI[1] = 0.0;
  unaff_ESI[2] = 0.0;
  return;
}

