
void FUN_006ee9c0(void)

{
  char *_Format;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined1 auStack_5c [12];
  char local_50 [68];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_5c;
  _Format = (char *)FUN_006ef4e0();
  _sprintf_s(local_50,0x40,_Format,in_stack_00000018,in_stack_0000001c);
  FUN_006ef570();
  __security_check_cookie(local_c ^ (uint)auStack_5c);
  return;
}

