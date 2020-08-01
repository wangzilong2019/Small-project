<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>后台管理</title>

	<%--引入文件html/css/jQuery--%>
	<%@include file="/pages/common/header.jsp"%>

	<style type="text/css">
	h1 {
		text-align: center;
		margin-top: 200px;
	}
</style>
</head>
<body>
	
	<div id="header">
			<img class="logo_img" alt="" src="../../static/img/logo.gif" >
			<span class="wel_word">后台管理系统</span>

		<%@include file="/pages/common/manger_menu.jsp"%>

	</div>
	
	<div id="main">
		<h1>欢迎管理员进入后台管理系统</h1>
	</div>

	<%--静态包含引入页脚--%>
	<%@include file="/pages/common/footer.jsp"%>

</body>
</html>