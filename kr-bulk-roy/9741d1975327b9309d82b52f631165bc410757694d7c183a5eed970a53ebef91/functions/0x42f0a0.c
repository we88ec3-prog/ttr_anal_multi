
void FUN_0042f0a0(void)

{
  undefined4 in_stack_00000018;
  undefined1 auStack_54 [4];
  char local_50 [68];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_54;
  _sprintf_s(local_50,0x40,"%p",in_stack_00000018);
  FUN_0042fe90();
  __security_check_cookie(local_c ^ (uint)auStack_54);
  return;
}

