
void FUN_0076e490(undefined4 param_1)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  DAT_00fba828 = DAT_00fba828 + 1;
  in_EAX[1] = DAT_00fba828;
  in_EAX[2] = param_1;
  *in_EAX = FoxUI::FXUIDockInfoLock::vftable;
  in_EAX[6] = 0;
  in_EAX[5] = 0;
  in_EAX[4] = 0;
  in_EAX[3] = 0;
  in_EAX[3] = *in_ECX;
  in_EAX[4] = in_ECX[1];
  in_EAX[5] = in_ECX[2];
  in_EAX[6] = in_ECX[3];
  return;
}

