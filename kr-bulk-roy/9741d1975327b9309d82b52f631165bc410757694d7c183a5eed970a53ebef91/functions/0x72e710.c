
void FUN_0072e710(undefined8 param_1)

{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 auStack_180 [56];
  undefined1 local_148 [260];
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)auStack_180;
  FUN_00730da0(local_148,&DAT_00c420d8,param_1);
  FUN_0072e770(unaff_ESI,unaff_EDI);
  __security_check_cookie(local_44 ^ (uint)auStack_180);
  return;
}

