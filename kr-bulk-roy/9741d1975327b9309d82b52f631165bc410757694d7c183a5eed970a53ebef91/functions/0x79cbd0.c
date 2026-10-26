
void FUN_0079cbd0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  float10 fVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 0.0;
  local_1c = 1.0;
  (**(code **)*DAT_00fba838)
            (*(undefined4 *)(in_EAX + 8),*(undefined4 *)(in_EAX + 0xc),(undefined4 *)(in_EAX + 0x10)
             ,&local_28);
  fVar2 = (float10)FUN_008ff0a0();
  local_28 = (float)((float10)0.0 * fVar2);
  local_20 = (float)fVar2;
  local_24 = local_28;
  fVar2 = (float10)FUN_008fef70();
  local_1c = (float)fVar2;
  puVar1 = (undefined4 *)FUN_0077e880(&local_28);
  if (&uStack_38 != puVar1) {
    uStack_2c = puVar1[3];
    uStack_38 = *puVar1;
    uStack_34 = puVar1[1];
    uStack_30 = puVar1[2];
  }
  FUN_0077f030(*(undefined4 *)(in_EAX + 8),*(undefined4 *)(in_EAX + 0xc),
               *(undefined4 *)(in_EAX + 0x10));
  FUN_0077efc0();
  return;
}

